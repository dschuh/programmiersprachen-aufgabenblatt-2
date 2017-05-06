# Build example
add_executable(example
  circle.cpp
  rectangle.cpp
  color.cpp
  mat2.cpp
  Vec2.cpp
  window.cpp
  glew.c
  example.cpp)
target_link_libraries(example
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES})
add_dependencies(example glfw nanovg ${COPY_BINARY})

# Build tests
add_executable(tests
  circle.cpp
  rectangle.cpp
  color.cpp
  mat2.cpp
  Vec2.cpp
  tests.cpp)
target_link_libraries(tests
  ${GLFW_LIBRARIES})


