# Examples

include_directories (SYSTEM ${Boost_INCLUDE_DIR} ${OPENSSL_INCLUDE_DIR})

add_executable(smtp_ex_sample ${PROJECT_SOURCE_DIR}/examples/smtps_simple_msg.cpp)
add_executable(smtp_ex_attachment ${PROJECT_SOURCE_DIR}/examples/smtps_attachment.cpp)
add_executable(smtp_ex_attachment ${PROJECT_SOURCE_DIR}/examples/smtps_attachment2.cpp)
add_executable(smtp_ex_utf8_msg ${PROJECT_SOURCE_DIR}/examples/smtp_utf8_qp_msg.cpp)

target_link_libraries(smtp_ex_sample ${LIBNAME} ${Boost_LIBRARIES} ${OPENSSL_LIBRARIES})
target_link_libraries(smtp_ex_attachment ${LIBNAME} ${Boost_LIBRARIES} ${OPENSSL_LIBRARIES})
target_link_libraries(smtp_ex_attachment2 ${LIBNAME} ${Boost_LIBRARIES} ${OPENSSL_LIBRARIES})
target_link_libraries(smtp_ex_utf8_msg ${LIBNAME} ${Boost_LIBRARIES} ${OPENSSL_LIBRARIES})