#include <Geode/Geode.hpp>
#include <cstdint>
using namespace geode::prelude;

$on_mod(Loaded) {
    
    static bool resetting = false;

    auto calculate = [] {
        if (resetting) return; 

        double num0 = Mod::get()->getSettingValue<double>("num0");
        double num1 = Mod::get()->getSettingValue<double>("num1");
        int8_t op = static_cast<int8_t>(Mod::get()->getSettingValue<int64_t>("Operation"));

        double result = 0;
        bool error = false;

        switch (op) {
            case 1: result = num0 + num1; break;
            case 2: result = num0 - num1; break;
            case 3: result = num0 * num1; break;
            case 4:
                if (num1 == 0) {
                    Notification::create("Error: division by zero!", NotificationIcon::Error)->show();
                    error = true;
                } else {
                    result = num0 / num1;
                }
                break;
            default: result = 0; break;
        }

        if (!error) {
            Notification::create(fmt::format("Result: {}", result), NotificationIcon::Info)->show();
        }

        
        resetting = true;
        Mod::get()->setSettingValue<double>("num0", 0.0);
        Mod::get()->setSettingValue<double>("num1", 0.0);
        resetting = false;
    };

     
    listenForSettingChanges<double>("num0", [calculate](double) { calculate(); });
    listenForSettingChanges<double>("num1", [calculate](double) { calculate(); });
    listenForSettingChanges<int64_t>("Operation", [calculate](int64_t) { calculate(); });
}
