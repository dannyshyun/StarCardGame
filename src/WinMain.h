#pragma once

extern s32  WINDOW_W;
extern s32  WINDOW_H;
extern int2 WINDOW_CENTER;
// 1フレームのCPU処理時間を取得(単位:μsec)
u64 GetCpuProfile();
