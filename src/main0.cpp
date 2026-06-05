#include <Geode/Geode.hpp>
#include <cstdint>
using namespace geode::prelude;
double result = 0;

$on_mod(Loaded) {
    auto calculate = [] {
        double num0 = Mod::get()->getSettingValue<double>("num0");
        double num1 = Mod::get()->getSettingValue<double>("num1");
        int8_t op = static_cast<int8_t>(Mod::get()->getSettingValue<int64_t>("Operation"));

        
        switch (op) {
            case 1: result = num0 + num1; break;
            case 2: result = num0 - num1; break;
            case 3: result = num0 * num1; break;
            case 4:
                if (num1 != 0) result = num0 / num1;
                break;
            default: break;
        }
        
    };
    Mod::get()->setSettingValue<double>("Answer", result);
    
    listenForSettingChanges<double>("num0", [calculate](double) { calculate(); });
    listenForSettingChanges<double>("num1", [calculate](double) { calculate(); });
    listenForSettingChanges<int64_t>("Operation", [calculate](int64_t) { calculate(); });

    
}
