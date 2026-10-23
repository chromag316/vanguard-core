# Vanguard: pinned external sources.
# Replaces the upstream modules.conf download so builds are reproducible.
# Bump a commit here deliberately, and record it in the deploy VERSION file.

# Playerbots (src/CMakeLists.txt)
set(PLAYERBOTS_GIT_REPOSITORY "https://github.com/cmangos/playerbots.git" CACHE STRING "Playerbots repository")
set(PLAYERBOTS_GIT_TAG "39d47006e4aa1658c7e17af15e4f63d47ec5a3eb" CACHE STRING "Playerbots commit")

# Modules (BUILD_MODULE_<NAME>). MODULES is the module framework itself.
set(MODULE_NAMES ACHIEVEMENTS MODULES)
set(MODULE_URLS
  "https://github.com/chromag316/vanguard-achievements-module.git"
  "https://github.com/flekz-games/cmangos-modules.git"
)
set(MODULE_TAGS
  "8a385c61cf7f4afb94a8fd991a9c142f9853eaaa"
  "f917cf5338d4eae191cb45fa6928db6941154670"
)
