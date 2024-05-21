////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2024 Laurent Gomila (laurent@sfml-dev.org)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Audio/SoundChannel.hpp>

#include <SFML/System/Angle.hpp>

#include <miniaudio.h>

#include <limits>


////////////////////////////////////////////////////////////
// Forward declarations
////////////////////////////////////////////////////////////

namespace sf
{
class Time;

namespace priv::MiniaudioUtils
{
struct SavedSettings
{
    float          pitch{1.f};
    float          pan{0.f};
    float          volume{1.f};
    ma_bool32      spatializationEnabled{MA_TRUE};
    ma_vec3f       position{0.f, 0.f, 0.f};
    ma_vec3f       direction{0.f, 0.f, -1.f};
    float          directionalAttenuationFactor{1.f};
    ma_vec3f       velocity{0.f, 0.f, 0.f};
    float          dopplerFactor{1.f};
    ma_positioning positioning{ma_positioning_absolute};
    float          minDistance{1.f};
    float          maxDistance{std::numeric_limits<float>::max()};
    float          minGain{0.f};
    float          maxGain{1.f};
    float          rollOff{1.f};
    ma_bool32      playing{MA_FALSE};
    ma_bool32      looping{MA_FALSE};
    float          innerAngle{degrees(360.f).asRadians()};
    float          outerAngle{degrees(360.f).asRadians()};
    float          outerGain{0.f};
};

[[nodiscard]] ma_channel    soundChannelToMiniaudioChannel(SoundChannel soundChannel);
[[nodiscard]] SoundChannel  miniaudioChannelToSoundChannel(ma_channel soundChannel);
[[nodiscard]] Time          getPlayingOffset(ma_sound& sound);
[[nodiscard]] ma_uint64     getFrameIndex(ma_sound& sound, Time timeOffset);
[[nodiscard]] SavedSettings saveSettings(const ma_sound& sound);
void                        applySettings(ma_sound& sound, const SavedSettings& savedSettings);

} // namespace priv::MiniaudioUtils
} // namespace sf
