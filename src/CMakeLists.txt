set (SRC
    Address.cpp
    main.cpp 
    Person.cpp   
    PhoneBook.cpp
    Phone.cpp
)

add_executable(register.x ${SRC})

target_include_directories(register.x PUBLIC ../include)