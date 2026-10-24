# Vanguard: pinned external sources, so builds are reproducible.
# Bump a commit here deliberately, and record it in the deploy VERSION file.

# Playerbots (src/CMakeLists.txt, BUILD_PLAYERBOTS)
set(PLAYERBOTS_GIT_REPOSITORY "https://github.com/cmangos/playerbots.git" CACHE STRING "Playerbots repository")
set(PLAYERBOTS_GIT_TAG "39d47006e4aa1658c7e17af15e4f63d47ec5a3eb" CACHE STRING "Playerbots commit")

# Achievements module (src/CMakeLists.txt, BUILD_ACHIEVEMENTS)
set(ACHIEVEMENTS_GIT_REPOSITORY "https://github.com/chromag316/vanguard-achievements-module.git" CACHE STRING "Achievements module repository")
set(ACHIEVEMENTS_GIT_TAG "bdb44c057b2bbdcf3ffdbac201d110cab9f048d5" CACHE STRING "Achievements module commit")
