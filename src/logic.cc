#include "logic.h"

#include <memory>
#include <thread>

#include "server.h"

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

//

void logic::StartServer() {
  srv           = std::make_unique<Server>(logic::OnRecv);
  server_thread = std::make_unique<std::thread>(&httplib::Server::listen_after_bind, srv.get());
}

void logic::OnRecv(const nlohmann::json& json) {
  std::cout << json << std::endl;
}
