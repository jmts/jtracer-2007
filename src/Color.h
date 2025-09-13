
#ifndef _COLOR_H_
#define _COLOR_H_

class Color
{
	private:
	float m_x[3];

	public:
	Color()
	{
		Color &c = *this;

		c(0) = 0.0;
		c(1) = 0.0;
		c(2) = 0.0;
	}

	Color(float fRed, float fGreen, float fBlue)
	{
		Color &c = *this;

		c(0) = fRed;
		c(1) = fGreen;
		c(2) = fBlue;
	}

	Color(const Color &d)
	{
		Color &c = *this;
		c(0) = d(0);
		c(1) = d(1);
		c(2) = d(2);
	}

	float& operator() (unsigned int i)
	{
		return m_x[i];
	}

	float operator() (unsigned int i) const
	{
		return m_x[i];
	}

	Color operator+=(const Color &u)
	{
		Color &c = *this;
		c(0) += u(0);
		c(1) += u(1);
		c(2) += u(2);

		return *this;
	}

	const Color operator+(const Color &u) const
	{
		return Color(*this) += u;
	}

	const Color clip() const
	{
		const Color &c = *this;

		float fRed   = c(0);
		float fGreen = c(1);
		float fBlue  = c(2);

		fRed   = (fRed   < 0.0f) ? 0.0f : fRed;
		fGreen = (fGreen < 0.0f) ? 0.0f : fGreen;
		fBlue  = (fBlue  < 0.0f) ? 0.0f : fBlue;

		fRed   = (fRed   > 1.0f) ? 1.0f : fRed;
		fGreen = (fGreen > 1.0f) ? 1.0f : fGreen;
		fBlue  = (fBlue  > 1.0f) ? 1.0f : fBlue;

		return Color(fRed, fGreen, fBlue);
	}
};

#endif
