#include "server.h"

#include <ftxui/component/event.hpp>

#include "screen.h"
#include "src/arguments.h"

static std::unique_ptr<std::thread> server_thread{};
static std::unique_ptr<Server>      srv{};

class _Thread_RAII {
 public:
  ~_Thread_RAII() {
    if (server_thread && server_thread->joinable()) {
      srv->stop();
      server_thread->join();
    }
  }
} static __thread_raii;

Server::Server() {
  bind_to_port("0.0.0.0", arguments::port);

  Post("/", [this](const auto &request, const auto &) {
    global::screen()->Post(ftxui::Event::Special(request.body));
  });
}

void Server::StartServer() {
  srv.reset(new Server{});
  server_thread = std::make_unique<std::thread>(&httplib::Server::listen_after_bind, srv.get());
}
