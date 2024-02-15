#pragma once

#include <httplib.h>

#include <nlohmann/json.hpp>

class Server final : public httplib::Server {
  using on_recv_t = std::function<void(const nlohmann::json &)>;

 public:
  explicit Server(on_recv_t OnRecv);

 private:
  on_recv_t OnRecv_;
};
