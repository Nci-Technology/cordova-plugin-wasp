package com.ca.waspHRM;

import com.google.gson.Gson;
import org.apache.cordova.PluginResult;
import org.apache.cordova.CordovaPlugin;
import org.apache.cordova.CallbackContext;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;
import android.content.Context;
import android.os.Build;
import java.util.ArrayList;
import android.util.Log;
import com.npe_inc.wasp.hrm_collector.HRM_Collector;
import com.npe_inc.wasp.hrm_collector.WaspHeartRateMonitor;

/**
 * The WaspHRMCollectorPlugin cordova wrapper for android
 *
 */
public class WaspHRMCollectorPlugin extends CordovaPlugin
        implements com.ca.waspHRM.WaspHRMCollectorMessageCallbackHandler {

    
    private static final boolean IS_AT_LEAST_LOLLIPOP = Build.VERSION.SDK_INT >= 21;
    private static final boolean IS_AT_LEAST_PIE = Build.VERSION.SDK_INT >= 28;
    JSONObject jobj = new JSONObject();    
    Context context = null;
    CallbackContext savedCallbackContext = null;
    private ArrayList<com.ca.waspHRM.WaspHRMModel> lst = new ArrayList<com.ca.waspHRM.WaspHRMModel>();
    private com.ca.waspHRM.WaspHRMCollectorBinding hrmCollectorBinding;

    @Override
    public boolean execute(String action, JSONArray args, CallbackContext callbackContext) throws JSONException {
        if (action.equals("doBind")) {
            String message = args.getString(0);
            this.doBind(message, callbackContext);
            return true;
        }
        if(action.equals("stopListener"))
        {
            this.stopListener();
            return true;
        }
        return false;
    }

    private void doBind(String message, CallbackContext callbackContext) {
        if (message != null && message.length() > 0) {

            savedCallbackContext = callbackContext;
            context = IS_AT_LEAST_LOLLIPOP ? cordova.getActivity().getWindow().getContext()
                    : cordova.getActivity().getApplicationContext();

            hrmCollectorBinding = new com.ca.waspHRM.WaspHRMCollectorBinding();

            hrmCollectorBinding.doBindService(context, (com.ca.waspHRM.WaspHRMCollectorMessageCallbackHandler) this);

        } else {
            callbackContext.error("Expected one non-empty string argument.");
        }
    }

    @Override
    public void HeartRateMonitorUpdate(WaspHeartRateMonitor waspHeartRateMonitor) {
        try {
            if (savedCallbackContext != null) {

               boolean deviceFound = false;
                    if(lst.size() == 0)
                    {
                        addHRMList(waspHeartRateMonitor);
                    }
                    else{
                    for (int i = 0; i < lst.size(); i++) {
                        if (lst.get(i).deviceNumber == waspHeartRateMonitor.getDeviceNumber()) {                          
                           lst.get(i).heartRate = waspHeartRateMonitor.getHeartRate();
                           lst.get(i).lastHeartBeatCount = waspHeartRateMonitor.getLastHeartBeatCount();
                           lst.get(i).packetsPerSecond = waspHeartRateMonitor.getPacketsPerSecond();                       
                           lst.get(i).rssi =  waspHeartRateMonitor.getRssi();
                           lst.get(i).lastSeenTimestampMS = waspHeartRateMonitor.getLastHeartBeatCount();
                           lst.get(i).version = hrmCollectorBinding.getVersion();
                           deviceFound = true;
                        }                        
                    }
                    if(!deviceFound)
                    addHRMList(waspHeartRateMonitor);
                }
                PluginResult pluginResult = new PluginResult(PluginResult.Status.OK, new Gson().toJson(lst));
                pluginResult.setKeepCallback(true);
                savedCallbackContext.sendPluginResult(pluginResult);

            }
        } catch (Exception e) {
            e.printStackTrace();
        }

    }

    @Override
    public void HeartRateMonitorConnectionLost(WaspHeartRateMonitor waspHeartRateMonitor) {

        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.N) {
            lst.removeIf(s -> s.deviceNumber == waspHeartRateMonitor.getDeviceNumber());
        } else {
            for (int i = 0; i < lst.size(); i++) {
                if (lst.get(i).deviceNumber == waspHeartRateMonitor.getDeviceNumber()) {
                    lst.remove(i);
                }
            }
        }

        if(lst.size()< 1)
        {
            PluginResult pluginResult = new PluginResult(PluginResult.Status.OK, new Gson().toJson(lst));            
            savedCallbackContext.sendPluginResult(pluginResult);  
        }

    }

    @Override
    public void onDestroy() {
        if(context == null)
        context = IS_AT_LEAST_LOLLIPOP ? cordova.getActivity().getWindow().getContext()
                : cordova.getActivity().getApplicationContext();
        hrmCollectorBinding.doUnbindService(context);
        super.onDestroy();
    }

    public void addHRMList(WaspHeartRateMonitor waspHeartRateMonitor)
    {
        com.ca.waspHRM.WaspHRMModel obj = new com.ca.waspHRM.WaspHRMModel();
        obj.deviceNumber = waspHeartRateMonitor.getDeviceNumber();
        obj.heartRate = waspHeartRateMonitor.getHeartRate();
        obj.lastHeartBeatCount = waspHeartRateMonitor.getLastHeartBeatCount();
        obj.packetsPerSecond = waspHeartRateMonitor.getPacketsPerSecond();
        obj.rssi = waspHeartRateMonitor.getRssi();
        obj.lastSeenTimestampMS = System.currentTimeMillis();
        obj.version = hrmCollectorBinding.getVersion();
        lst.add(obj);
    }

    public void stopListener()
    {
        if(context == null)
        context = IS_AT_LEAST_LOLLIPOP ? cordova.getActivity().getWindow().getContext()
                : cordova.getActivity().getApplicationContext();
        hrmCollectorBinding.doUnbindService(context);
    }
}
