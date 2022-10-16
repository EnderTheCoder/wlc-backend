//
// Created by ender on 22-10-15.
//
#include "./controller/AdminController.hpp"
#include "./AppComponent.hpp"

#include "oatpp/network/Server.hpp"
#include "ServiceComponent.hpp"
#include "DatabaseComponent.hpp"

void run(const oatpp::base::CommandLineArguments& args) {

    AppComponent appComponent(args);
    DatabaseComponent databaseComponent;
    ServiceComponent serviceComponent;
//    ClientComponent clientComponent;
    /* create ApiControllers and add endpoints to router */

    auto router = serviceComponent.httpRouter.getObject();
    oatpp::web::server::api::Endpoints endpoints;

    endpoints.append(router->addController(AdminController::createShared())->getEndpoints());
    router->addController(AdminController::createShared());
    oatpp::network::Server server(serviceComponent.serverConnectionProvider.getObject(),serviceComponent.serverConnectionHandler.getObject());
    OATPP_LOGD("Server", "Running on %s:%s", serviceComponent.serverConnectionProvider.getObject()->getProperty("host").toString()->c_str(), serviceComponent.serverConnectionProvider.getObject()->getProperty("port").toString()->c_str());

    server.run();

}

/**
 *  main
 */
int main(int argc, const char * argv[]) {
    oatpp::base::Environment::init();

    run(oatpp::base::CommandLineArguments(argc, argv));

    oatpp::base::Environment::destroy();

    return 0;
}
