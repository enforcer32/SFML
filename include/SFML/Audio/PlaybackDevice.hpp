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
#include <SFML/Audio/Export.hpp>

#include <string>
#include <vector>


namespace sf::PlaybackDevice
{
////////////////////////////////////////////////////////////
/// \brief Get a list of the names of all available audio playback devices
///
/// This function returns a vector of strings, containing
/// the names of all available audio playback devices.
///
/// If the operating system reports multiple devices with
/// the same name, starting from the second device a number
/// is appended to the name to distinguish the devices from
/// each other. This guarantees that every entry returned
/// by this function will represent a unique device.
///
/// The default device, if one is marked as such, will be
/// placed at the beginning of the vector.
///
/// \return A vector of strings containing the names
///
////////////////////////////////////////////////////////////
std::vector<std::string> SFML_AUDIO_API getAvailableDevices();

////////////////////////////////////////////////////////////
/// \brief Get the name of the default audio playback device
///
/// This function returns the name of the default audio
/// playback device. If none is available, an empty string
/// is returned.
///
/// \return The name of the default audio playback device
///
////////////////////////////////////////////////////////////
std::string SFML_AUDIO_API getDefaultDevice();

////////////////////////////////////////////////////////////
/// \brief Set the audio playback device
///
/// This function sets the audio playback device to the device
/// with the given \a name. It can be called on the fly (i.e:
/// while recording).
///
/// \param name The name of the audio playback device
///
/// \return True, if it was able to set the requested device
///
/// \see getAvailableDevices, getDefaultDevice
///
////////////////////////////////////////////////////////////
[[nodiscard]] bool SFML_AUDIO_API setDevice(const std::string& name);

////////////////////////////////////////////////////////////
/// \brief Get the name of the current audio playback device
///
/// \return The name of the current audio playback device
///
////////////////////////////////////////////////////////////
std::string SFML_AUDIO_API getDevice();

} // namespace sf::PlaybackDevice
