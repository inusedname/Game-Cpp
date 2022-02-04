#include "Map.h"

Map::Map()
{
    NUM_LANES = 13;
    Lane tmp;
    for (int i = 1; i <= 3; i++)
    {
        tmp.setLanePosition(0, 720 - (128 * i));
        tmp.refreshSafe();
        lanes.push_front(tmp);
    } // 3 dòng đầu tiên sẽ là chỗ bắt đầu
    for (int i = 4; i <= NUM_LANES; i++)
    {
        tmp.setLanePosition(0, 720 - (128 * i));
        tmp.refresh();
        lanes.push_front(tmp);
    }
}
void Map::Draw(RenderWindow *window)
{
    for (int i = 1; i <= NUM_LANES; i++)
        lanes[i].Draw(window);
}
void Map::refresh()
{
    Lane tmp = lanes.
}