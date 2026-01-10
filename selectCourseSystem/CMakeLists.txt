cmake_minimum_required(VERSION 4.1.1)

#https://github.com/Kitware/CMake/blob/v4.1.1/Help/dev/experimental.rst

set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "d0edc3af-4c50-42ea-a356-e2862fe7a444")
set(CMAKE_CXX_MODULE_STD ON)

project(selecteCoursesSystem LANGUAGES CXX)

# set(MODULE_LIB_DIR1 /opt/utils/modules)  # 模块库的目录的设置
add_executable(selecteCoursesSystem
    #math.cpp                              # 模块实现单元
    main.cpp
    student.dat
    course.dat
    teach.dat
)

set(REGISTRAR_FILES
   #总分区
   registrar.cppm
)

set(PRESENTATION_LAYER_FILES
   #表现层模块分区
   ui.cppm
)

set(APPLICATION_LAYER_FILES
    #应用逻辑层模块分区
    controller.cppm
    studentcontroller.cppm
    teachercontroller.cppm
    academicsecretarycobtroller.cppm
)

set(DOMAIN_LAYER_FILES
    #领域层模块分区
    domain.cppm
    person.cppm
    student.cppm
    teacher.cppm
    academicsecretary.cppm
    course.cppm
)

set(DATA_ACCESS_LAYER_FILES
    #数据管理层模块分区
    databaseManger.cppm
    InitiallzeDatabase.cppm
    database.cppm
    daStudent.cppm
    daCourse.cppm
    daTeach.cppm
)

source_group("Registrar" FILES ${REGISTRAR_FILES})

source_group("Presentation Layer" FILES ${PRESENTATION_LAYER_FILES})

source_group("Application Layer" FILES ${APPLICATION_LAYER_FILES})

source_group("Domain Layer" FILES ${DOMAIN_LAYER_FILES})

source_group("Data Access Layer" FILES ${DATA_ACCESS_LAYER_FILES})




target_sources(selecteCoursesSystem  PRIVATE FILE_SET cxx_modules TYPE CXX_MODULES
    BASE_DIRS                              # 配置BASE_DIRS，用于组织构建输出目录，以便构建不同目录中(同名的)模块文件.
        ${CMAKE_CURRENT_SOURCE_DIR}
    FILES ${PRESENTATION_LAYER_FILES} ${APPLICATION_LAYER_FILES} ${DOMAIN_LAYER_FILES} ${DATA_ACCESS_LAYER_FILES} ${REGISTRAR_FILES}
)
target_compile_features(selecteCoursesSystem PRIVATE cxx_std_23)












































# target_link_directories(selectGradeSystem PRIVATE /opt/utils/lib)  # -L /opt/utils/lib 设置链接路径
# target_link_libraries(selectGradeSystem PRIVATE utils)             # -lutils           设置链接库名

# set_target_properties(selectGradeSystem PROPERTIES
#     INSTALL_RPATH_USE_LINK_PATH  True                           # 使用链接路径作为安装文件的RPath，等价于"-Wl,-rpath=/opt/utils/lib"
# )

#add_library(selectGradeSystem SHARED
#  utils.cpp
#)

#set_target_properties( selectGradeSystem PROPERTIES
#    PUBLIC_HEADER utils.cppm
#    VERSION   2.5.1
#    SOVERSION 2
#    LIBRARY_OUTPUT_DIRECTORY  "${CMAKE_BINARY_DIR}/lib"
#)

#install(TARGETS selectGradeSystem
#    LIBRARY DESTINATION /opt/utils/lib
#    PUBLIC_HEADER DESTINATION  /opt/utils/modules
#)

#add_custom_command(TARGET selectGradeSystem
#    POST_BUILD
#    COMMAND cmake --install "${CMAKE_CURRENT_BINARY_DIR}"
#)
