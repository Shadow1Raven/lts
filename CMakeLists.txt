cmake_minimum_required(VERSION 3.8)
project(lts)

if (NOT(DEFINED ENV{IRRLICHT_INCLUDE_DIR}))
	message(FATAL_ERROR "$IRRLICHT_INCLUDE_DIR must be set to the directory where the irrlicht directory is.")
endif()

configure_file(testdata/objects objects COPYONLY)
configure_file(testdata/models/person.3ds models/person.3ds COPYONLY)
configure_file(testdata/models/shelf_cheap.3ds models/shelf_cheap.3ds COPYONLY)
configure_file(testdata/testlot/testfile.ter testlot/testfile.ter COPYONLY)
configure_file(testdata/testlot/core.lot testlot/core.lot COPYONLY)
configure_file(testdata/testlot/128 testlot/128 COPYONLY)

set(LTS_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)
set(LTS_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)

set(LTS_SOURCES
	${LTS_SOURCE_DIR}/main.cpp

	${LTS_SOURCE_DIR}/map/objectlocation.cpp
	${LTS_SOURCE_DIR}/map/tilealignedboundingbox.cpp
	${LTS_SOURCE_DIR}/map/changeabilitymap.cpp
	${LTS_SOURCE_DIR}/map/storey.cpp
	${LTS_SOURCE_DIR}/map/terrainmap.cpp
	${LTS_SOURCE_DIR}/map/lot.cpp

	${LTS_SOURCE_DIR}/scene/lotscenenode.cpp
	${LTS_SOURCE_DIR}/scene/storeyscenenode.cpp
)

set(LTS_INCLUDES
	${LTS_INCLUDE_DIR}/lts/main.hpp
	${LTS_INCLUDE_DIR}/lts/aliases.hpp

	${LTS_INCLUDE_DIR}/lts/map/objectlocation.hpp
	${LTS_INCLUDE_DIR}/lts/map/tilealignedboundingbox.hpp
	${LTS_INCLUDE_DIR}/lts/map/changeabilitymap.hpp
	${LTS_INCLUDE_DIR}/lts/map/storey.hpp
	${LTS_INCLUDE_DIR}/lts/map/terrainmap.hpp
	${LTS_INCLUDE_DIR}/lts/map/lot.hpp

	${LTS_INCLUDE_DIR}/lts/scene/lotscenenode.hpp
	${LTS_INCLUDE_DIR}/lts/scene/storeyscenenode.hpp
)

include_directories(${LTS_INCLUDE_DIR})

add_executable(${PROJECT_NAME} ${LTS_SOURCES} ${LTS_INCLUDES})
target_link_libraries(${PROJECT_NAME} Irrlicht)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_14)
