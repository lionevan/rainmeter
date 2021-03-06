/*
  Copyright (C) 2001 Kimmo Pekkola

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation; either version 2
  of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#ifndef __MEASURETIME_H__
#define __MEASURETIME_H__

#include "Measure.h"

class MeasureTime : public Measure
{
public:
	MeasureTime(MeterWindow* meterWindow, const WCHAR* name);
	virtual ~MeasureTime();

	virtual UINT GetTypeID() { return TypeID<MeasureTime>(); }

	virtual const WCHAR* GetStringValue();

protected:
	virtual void ReadOptions(ConfigParser& parser, const WCHAR* section);
	virtual void UpdateValue();

private:
	void TimeToString(WCHAR* buf, size_t bufLen, const WCHAR* format, const tm* time);
	void FillCurrentTime();

	std::wstring m_Format;
	LARGE_INTEGER m_DeltaTime;
	LARGE_INTEGER m_Time;

	double m_TimeStamp;
};

#endif
