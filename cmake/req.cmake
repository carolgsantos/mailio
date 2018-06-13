
if(WIN32)
    # Add dyn link only for shared library
	add_definitions(-DBOOST_ALL_NO_LIB -DBOOST_ALL_DYN_LINK)
    #SET(Boost_USE_STATIC_LIBS ON)
endif(WIN32)
find_package(Boost REQUIRED COMPONENTS system date_time regex random)

find_package(OpenSSL)
