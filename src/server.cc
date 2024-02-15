#include "server.h"

#include "src/arguments.h"

Server::Server(on_recv_t OnRecv) : OnRecv_{std::move(OnRecv)} {
  bind_to_port("0.0.0.0", arguments::port);

  Post("/", [this](const auto &request, const auto &) {
    OnRecv_(nlohmann::json::parse(request.body));
  });
}
