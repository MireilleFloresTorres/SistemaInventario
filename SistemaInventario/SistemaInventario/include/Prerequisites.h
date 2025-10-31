#pragma once
#include<string>
#include<iostream>
#include<vector>

#include <json.hpp>

using json = nlohmann::json;

json j = {
    {"name", "John Doe"},
    {"age", 30},
    {"is_student", false},
    {"skills", {"C++", "Python", "JavaScript"}}
};
