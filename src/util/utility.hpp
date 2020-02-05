/*************************************************************************
 * This file is part of tuna
 * github.con/univrsal/tuna
 * Copyright 2020 univrsal <universailp@web.de>.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *************************************************************************/

#pragma once

#include <QString>
#include <obs-module.h>
#include <stdint.h>

#define write_log(log_level, format, ...) blog(log_level, "[tuna] " format, ##__VA_ARGS__)

#define bdebug(format, ...) write_log(LOG_DEBUG, format, ##__VA_ARGS__)
#define binfo(format, ...) write_log(LOG_INFO, format, ##__VA_ARGS__)
#define bwarn(format, ...) write_log(LOG_WARNING, format, ##__VA_ARGS__)
#define berr(format, ...) write_log(LOG_ERROR, format, ##__VA_ARGS__)

#define SECOND_TO_NS 1000000000
class song;

namespace util {
extern bool vlc_loaded;

void load_vlc();

void unload_vlc();

bool curl_download(const QString& url, const QString& path);

void download_cover(const song* song);

void download_lyrics(const song* song);

void handle_outputs(const song* song);

bool move_file(const QString& src, const QString& dest);

int64_t epoch();

inline const char* qcstr(const QString& str)
{
    auto ba = str.toLocal8Bit();
    return ba.constData();
}

} // namespace util
