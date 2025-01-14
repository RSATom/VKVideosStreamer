#pragma once

#include <map>

#include <spdlog/common.h>


struct Config
{
    struct ReStreamer;

    spdlog::level::level_enum logLevel = spdlog::level::info;

    std::map<std::string, ReStreamer> reStreamers; // id -> ReStreamer
};

struct Config::ReStreamer {
    ReStreamer(
        const std::string& source,
        const std::string& description,
        const std::string& key,
        bool enabled):
        source(source),
        description(description),
        key(key),
        enabled(enabled) {}
    ReStreamer(const ReStreamer& reStreamer):
        source(reStreamer.source),
        description(reStreamer.description),
        key(reStreamer.key),
        enabled(reStreamer.enabled) {}
    ReStreamer(ReStreamer&& reStreamer):
        source(std::move(reStreamer.source)),
        description(std::move(reStreamer.description)),
        key(std::move(reStreamer.key)),
        enabled(reStreamer.enabled) {}

    std::string source;
    std::string description;
    std::string key;
    bool enabled;
    std::string forceH264ProfileLevelId = "42c015";
};
