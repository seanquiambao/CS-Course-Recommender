# Copyright (c) 2014-present, Facebook, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.

cmake_minimum_required(VERSION 3.17.5)
project(thirdparty_sqlite)

option(SQLITE_ENABLE_INSTALL_TARGET "When enabled, will cause the project to create the install targets" OFF)
option(SQLITE_ENABLE_FULL_TEXT_SEARCH_EXTENSIONS "Set to ON to enable the FTS extensions" OFF)
option(SQLITE_ENABLE_RTREE_EXTENSION "Set to ON to enable the R*Tree module" OFF)

function(sqliteMain)
  set(parameter_list
   "SQLITE_VERSION=3.39.2"
   "SQLITE_MAX_VARIABLE_NUMBER=250000"
  )

  set(option_list
    SQLITE_ENABLE_COLUMN_METADATA
    SQLITE_SECURE_DELETE
    SQLITE_ENABLE_UNLOCK_NOTIFY
    SQLITE_ENABLE_DBSTAT_VTAB
    SQLITE_ENABLE_JSON1
    SQLITE_ENABLE_PREUPDATE_HOOK
    SQLITE_ENABLE_SESSION
    SQLITE_SOUNDEX
  )

  if(${SQLITE_ENABLE_RTREE_EXTENSION})
    message(STATUS "Enabling the SQLite R*Tree module")

    list(APPEND option_list
      SQLITE_ENABLE_RTREE
    )

  else()
    message(STATUS "Disabling the SQLite R*Tree module")
  endif()

  if(${SQLITE_ENABLE_FULL_TEXT_SEARCH_EXTENSIONS})
    message(STATUS "Enabling the SQLite FTS extensions")

    list(APPEND option_list
      SQLITE_ENABLE_FTS3
      SQLITE_ENABLE_FTS3_PARENTHESIS
      SQLITE_ENABLE_FTS5
    )

  else()
    message(STATUS "Disabling the SQLite FTS extensions")
  endif()

  add_library(thirdparty_sqlite
    src/sqlite3.c
  )

  target_compile_definitions(thirdparty_sqlite PRIVATE
    ${parameter_list}
  )

  foreach(option ${option_list})
    target_compile_definitions(thirdparty_sqlite PRIVATE
      "${option}=1"
    )
  endforeach()

  target_include_directories(thirdparty_sqlite INTERFACE
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
  )

  if(SQLITE_ENABLE_INSTALL_TARGET)
    message(STATUS "Enabling the install target")

    install(TARGETS thirdparty_sqlite DESTINATION lib)
    install(FILES src/sqlite3ext.h src/sqlite3.h DESTINATION include)
  endif()
endfunction()

sqliteMain()