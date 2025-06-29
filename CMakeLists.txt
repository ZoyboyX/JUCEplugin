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
project(SampleJucePlugin VERSION 0.1 LANGUAGES CXX)

# Point to your JUCE clone
set(JUCE_DIR "$ENV{HOME}/JUCE")
include(${JUCE_DIR}/extras/Build/JUCE/CMakeLists.txt)

# Define plugin target
juce_add_plugin(SampleJucePlugin
    COMPANY_NAME Sample
    PLUGIN_MANUFACTURER_CODE Snpl
    PLUGIN_CODE Sppl
    FORMATS         VST3
)

target_sources(SampleJucePlugin PRIVATE
    Source/PluginProcessor.cpp
    Source/PluginEditor.cpp
)
juce_generate_juce_header(SampleJucePlugin)
target_compile_features(SampleJucePlugin PRIVATE cxx_std_14)


