# Bubble
# Copyright © 2020 otreblan
#
# integer is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# integer is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with integer.  If not, see <http://www.gnu.org/licenses/>.

cmake_minimum_required(VERSION 3.13.0)

# Módulos de cmake
include(GNUInstallDirs)

# El nombre del proyecto
project(bubble
	VERSION 0.0.0
	DESCRIPTION "Bubble"
	HOMEPAGE_URL "https://github.com/utec-computer-science/cs1103-pointer-func-otreblan"
	LANGUAGES "CXX"
)

# El programa en sí
add_executable(${PROJECT_NAME})

# Sín esto el target_sources() no resuelve path's relativos.
cmake_policy(SET CMP0076 NEW)

# Source files
add_subdirectory(src)

# Headers
target_include_directories(${PROJECT_NAME}
	PRIVATE ${PROJECT_SOURCE_DIR}/include
)

# El estandard de C++
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)

# Flags para el compilador
if(NOT DEFINED ENV{CXXFLAGS})
	set(CMAKE_CXX_FLAGS "-Wall -g")
endif()


# Definiciones para la instalación
install(TARGETS ${PROJECT_NAME}
	DESTINATION ${CMAKE_INSTALL_BINDIR}
)
