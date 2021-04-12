package com.ca.waspHRM;

import com.npe_inc.wasp.hrm_collector.WaspHeartRateMonitor;

public interface WaspHRMCollectorMessageCallbackHandler {
    public void HeartRateMonitorUpdate(WaspHeartRateMonitor waspHeartRateMonitor);
    public void HeartRateMonitorConnectionLost(WaspHeartRateMonitor waspHeartRateMonitor);
}
