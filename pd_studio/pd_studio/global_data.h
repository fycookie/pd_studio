#pragma once

struct SignalData
{
	double t = 0;
	double x = 0;
	double y = 0;
	double z = 0;
    double o = 0;
};

struct ResultantAcc
{
	double time = 0;
	double data = 0;
};

enum SigTypeByAxis
{
	x_axis,
	y_axis,
	z_axis,
	o_axis
};

enum FileSuffixType
{
    csv,
    txt,
    xls
};

enum TrimSignalType
{
    trimExport,
    trimReset,
    trimSave
};

struct TabEditType
{
    int TrimTab = 1;
	int FilterTab = 2;
	int FFTTab = 3;
};
