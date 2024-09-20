/* Inversion of Control (IoC) in C++ refers to a design principle where the flow of a program's control is inverted compared 
to traditional procedural programming. Instead of components controlling the flow of the entire application, control is delegated 
to external frameworks or containers that manage the flow of the program. This is typically achieved through mechanisms such as 
dependency injection, where dependencies are injected into a component rather than the component creating or managing its own 
dependencies. In practical terms, IoC helps in achieving loosely coupled and more modular code, making it easier to maintain and 
test. It promotes separation of concerns and allows components to be more reusable and interchangeable.


In software engineering, inversion of control (IoC) is a design principle in which custom-written portions of a computer program 
receive the flow of control from a generic framework. The term "inversion" is historical: a software architecture with this design 
"inverts" control as compared to procedural programming. 

In procedural programming, a program's custom code calls reusable libraries to take care of generic tasks, but with inversion of 
control, it is the framework that calls the custom code.


Frameworks like Spring (Java) and libraries such as Boost (C++) provide tools and patterns to implement IoC effectively in C++ 
applications. */

#include <iostream>
#include <memory>
using namespace std;

// Interface representing a service
class IService {
public:
    virtual void execute() = 0;
    virtual ~IService() {}
};

// Concrete implementation of IService
class Service : public IService {
public:
    void execute() override {
        cout << "Executing Service" << endl;
    }
};

// Client class that depends on IService
class Client {
private:
    shared_ptr<IService> service;

public:
    // Constructor with dependency injection
    Client(shared_ptr<IService> svc) : service(svc) {}

    void performAction() {
        // Client uses the injected service without knowing its implementation details
        service->execute();
    }
};

int main() {
    // Creating an instance of Service
    shared_ptr<IService> service = make_shared<Service>();

    // Creating an instance of Client and injecting the Service
    Client client(service);

    // Client performs some action
    client.performAction();

    return 0;
}

/* In this example:

IService is an interface that defines the contract for a service.
Service is a concrete implementation of IService.
Client is a class that depends on IService.
In main(), we create an instance of Service and inject it into the Client object.
Here, the control of creating and managing the Service instance is inverted. Instead of Client creating an instance of Service 
directly, Service is created outside and passed (injected) into Client via its constructor. This way, Client doesn't have direct 
control over the creation and lifetime of Service, following the Inversion of Control principle.
 */





