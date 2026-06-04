#include <Geode/Geode.hpp>
#include <cstdint>
using namespace geode::prelude;

$on_mod(Loaded) {
    l

        double num0 = Mod::get()->getSettingValue<double>("num0");
        double num1 = Mod::get()->getSettingValue<double>("num1");
        int8_t op = static_cast<int8_t>(Mod::get()->getSettingValue<int64_t>("Operation"));

        double result = 0;
        switch (op) {
            case 1: result = num0 + num1; break;
            case 2: result = num0 - num1; break;
            case 3: result = num0 * num1; break;
            case 4:
                if (num1 == 0) {
                    Notification::create("Error: division by zero!", NotificationIcon::Error)->show();
                    result = 0;
                } else {
                    result = num0 / num1;
                }
                break;
            default: result = 0; break;
        }

        if (!(op == 4 && num1 == 0)) {
            Notification::create(fmt::format("Result: {}", result), NotificationIcon::Info)->show();
        }

    
    });
}
