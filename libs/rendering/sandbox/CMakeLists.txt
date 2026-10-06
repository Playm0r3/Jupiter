add_executable(rendering_sandbox main.cpp)

target_link_libraries(rendering_sandbox PRIVATE soleil SDL3::SDL3)

add_custom_command(TARGET rendering_sandbox POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:SDL3::SDL3>
        $<TARGET_FILE_DIR:rendering_sandbox>
)