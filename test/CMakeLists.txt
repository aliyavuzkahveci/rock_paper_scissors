set(TARGET_NAME unittest)

get_filename_component(PARENT_DIR ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)

#Remove main.cpp of parent project from the list.
list(REMOVE_ITEM SOURCE_EXTENSION "${PARENT_DIR}/src/main.cpp")

#Find source and header files.
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SOURCE_EXTENSION)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} HEADER_EXTENSION)

add_executable(${TARGET_NAME} ${SOURCE_EXTENSION} ${HEADER_EXTENSION})

target_link_libraries(${TARGET_NAME} PUBLIC gtest gmock)

add_test(${TARGET_NAME} ${TARGET_NAME})
