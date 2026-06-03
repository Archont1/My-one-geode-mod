cmake_minimum_required(VERSION 3.15)
project(CalculatorInSettingsMod)

find_package(Geode REQUIRED)

geode_mod(${PROJECT_NAME}
    
    SOURCES archont001.calculator-in-settings.android64.cpp
)