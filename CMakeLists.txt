# ==============================================================================
#
#  This file is part of the JUCE framework.
#  Copyright (c) Raw Material Software Limited
#
#  JUCE is an open source framework subject to commercial or open source
#  licensing.
#
#  By downloading, installing, or using the JUCE framework, or combining the
#  JUCE framework with any other source code, object code, content or any other
#  copyrightable work, you agree to the terms of the JUCE End User Licence
#  Agreement, and all incorporated terms including the JUCE Privacy Policy and
#  the JUCE Website Terms of Service, as applicable, which will bind you. If you
#  do not agree to the terms of these agreements, we will not license the JUCE
#  framework to you, and you must discontinue the installation or download
#  process and cease use of the JUCE framework.
#
#  JUCE End User Licence Agreement: https://juce.com/legal/juce-8-licence/
#  JUCE Privacy Policy: https://juce.com/juce-privacy-policy
#  JUCE Website Terms of Service: https://juce.com/juce-website-terms-of-service/
#
#  Or:
#
#  You may also use this code under the terms of the AGPLv3:
#  https://www.gnu.org/licenses/agpl-3.0.en.html
#
#  THE JUCE FRAMEWORK IS PROVIDED "AS IS" WITHOUT ANY WARRANTY, AND ALL
#  WARRANTIES, WHETHER EXPRESSED OR IMPLIED, INCLUDING WARRANTY OF
#  MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE, ARE DISCLAIMED.
#
# ==============================================================================

cmake_minimum_required(VERSION 3.15)
project(MyJucePlugin VERSION 0.1 LANGUAGES CXX)

# point CMake at the JUCE root
set(JUCE_DIR "$ENV{HOME}/JUCE")
include(${JUCE_DIR}/extras/Build/JUCE/CMakeLists.txt)

# register your plug-in
juce_add_plugin(MyJucePlugin
  COMPANY_NAME    YourName
  PLUGIN_MANUFACTURER_CODE Your
  PLUGIN_CODE     Plg1
  FORMATS         VST3  # add AU if on macOS
)

target_sources(MyJucePlugin
  PRIVATE
    Source/PluginProcessor.cpp
    Source/PluginEditor.cpp
)
juce_generate_juce_header(MyJucePlugin)

