#ifndef LEVELSTATE_H
#define LEVELSTATE_H
#include <QMetaEnum>

enum class LevelState {
    PREPARING,
    RUNNING,
    WON,
    FAILED,
};
#endif // LEVELSTATE_H
