# Copyright (c) 2024 GP Orcullo
# SPDX-License-Identifier: Apache-2.0

project(UDYNLINK)

if(CONFIG_UDYNLINK)
    zephyr_include_directories(..)
    zephyr_sources(../udynlink/udynlink.c)
endif()
