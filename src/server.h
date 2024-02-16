#pragma once

#define CPPHTTPLIB_THREAD_POOL_COUNT 1
#include <httplib.h>

#include <nlohmann/json.hpp>

namespace ftxui {
class ScreenInteractive;
}
class Server final : public httplib::Server {
 public:
  static void StartServer();

 private:
  explicit Server();
};
