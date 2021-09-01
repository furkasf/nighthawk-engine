#pragma once
#include<string>

class loadPrams
{
public:
	
	loadPrams(int x, int y, int width, int height,std::string textureID, int frameNumber, int callbackID = 0, int animeSpeed = 0) : m_x{x}, m_y{y}, m_width{width}
		, m_height{height} , m_textureID{ textureID }, m_frameNumber{ frameNumber }, m_callBackID{ callbackID }, m_animSpeed{ animeSpeed }
	{
	}

	int get_x()									{ return m_x;				}
	int get_x() const							{ return m_x;				}
	
	int get_y()									{ return m_y;				}
	int get_y() const							{ return m_y;				}

	int get_frameNumber()						{ return m_frameNumber;		}
	int get_frameNumber() const					{ return m_frameNumber;		}

	int get_callBackID()						{ return m_callBackID;		}
	int get_callBackID() const					{ return m_callBackID;		}

	int get_animSpeed()							{ return m_animSpeed;		}
	int get_animSpeed() const					{ return m_animSpeed;		}
		
	int get_width()								{ return m_width;			}
	int get_width() const						{ return m_width;			}

	int get_height()							{ return m_height;			}
	int get_height() const						{ return m_height;			}

	std::string get_textureID()					{ return m_textureID;		}
	std::string get_textureID() const			{ return m_textureID;		}

private:

	int m_x;
	int m_y;

	int m_width;
	int m_height;

	int m_frameNumber;
	int m_animSpeed;

	int m_callBackID;

	std::string m_textureID;
};

