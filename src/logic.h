#pragma once

#include <nlohmann/json.hpp>
namespace logic {

void StartServer();

void OnRecv(const nlohmann::json& json);

}  // namespace logic
