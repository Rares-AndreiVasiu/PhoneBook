set (SRC
    Address.cpp
    main.cpp 
    Person.cpp   
    PhoneBook.cpp
    Phone.cpp
    Menu.cpp
    utils.cpp
    handler.cpp
    linkedList.cpp   
)

add_executable(register.x ${SRC})

target_include_directories(register.x PUBLIC ../include)