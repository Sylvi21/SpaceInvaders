#ifndef LEVELSTATE_H
#define LEVELSTATE_H
#include <QMetaEnum>

enum class LevelState {
    PREPARING,
    RUNNING,
    BOSSTIME,
    WON,
    FAILED,
};
#endif // LEVELSTATE_H
