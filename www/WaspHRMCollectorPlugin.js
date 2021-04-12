var exec = require('cordova/exec');
var TAG = 'WHRCMPlugin.js';

var defaultHRMListener = {
    startListener : function (success, error) {
        var opts = {};
        exec(success, error, 'WaspHRMCollectorPlugin', 'doBind', [opts]);
    },
    stopListener : function (success, error) {
        var opts = {};
        exec(success, error, 'WaspHRMCollectorPlugin', 'stopListener', [opts]);
    }
};

function scanForWifiWithRetries(success, error, opts, tries)
{
    console.log(TAG + ': scanForWifiWithRetries: ' + tries);
    var target_error_string = 'E201: No Wasps Found';
    if (tries <= 0) {
        error(target_error_string);
        return;
    }
    error_wrap = function (error_string) { 
        if (error_string == target_error_string)
            setTimeout(function(){scanForWifiWithRetries(success, error, opts , tries - 1)}, 3000);
        else
            error(error_string);
    };
    exec(success, error_wrap, 'WaspHRMCollectorPlugin', 'scanForWifiNetworks', [opts]);
}

var limitedAPConfigurator =  {
    requestWaspConfig : function (success, error) {
        var opts = {};
        exec(success, error, 'WaspHRMCollectorPlugin', 'requestWaspConfig', [opts]);
    },

    getCurrentWaspConfig : function (success, error) {
        var opts = {};
        exec(success, error, 'WaspHRMCollectorPlugin', 'getCurrentWaspConfig', [opts]);
    },

    scanForWifiNetworks : function (success, error) {
        var opts = {};
        scanForWifiWithRetries(success, error, opts, 3);
    },

    resetToOemDefaults : function (success, error) {
        var opts = {};
        exec(success, error, 'WaspHRMCollectorPlugin', 'resetToOemDefaults', [opts]);
    },

    setWifiConfig : function (wifiSettings, success, error) {
        exec(success, error, 'WaspHRMCollectorPlugin', 'setWifiConfig', [wifiSettings]);
    }
};

module.exports = {
    getLimitedAPConfigurator : function (opts) {
        // Argument opts unused in early revs
        if (cordova.platformId == 'ios') {
            return limitedAPConfigurator;
        } else {
            function logPlatformRequirement() {
                console.log(TAG + ': Only iOS supported for configuration!');
            }

            // Force visible alert at top level
            alert('WaspHRMCollectorPlugin: WASP configuration API currently only supported on iOS!');

            // Log error *and* return a dummy errorLogger object 
            logPlatformRequirement();
            return {
                requestWaspConfig : logPlatformRequirement,
                getCurrentWaspConfig : logPlatformRequirement,
                scanForWifiNetworks : logPlatformRequirement,
                setWifiConfig : logPlatformRequirement
            }
        }
    },
    getDefaultHRMListener : function (opts) {
        // Argument opts unused in early revs
        return defaultHRMListener;
    }
}
