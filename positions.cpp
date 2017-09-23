//! Implementation of positions.h

Position::Position() {
	myRadius = 1;
	myAngleInRadians = 0;
}

Position::Position(float r) {
	myRadius = r;
	myAngleInRadians = 0;	
}

Position::Position(float r, float thetaInRadians) {
	myRadius = r;
	myAngleInRadians = thetaInRadians;	
}


void Position::SetAbsolutePosition(float r, float thetaInRadians) {
	const float pi = 3.14159265358979323846;

	if (thetaInRadians < 0) {
		thetaInRadians += 2 *pi;
	}
	
	if (thetaInRadians > 2 * pi) {
		thetaInRadians = fmod(thetaInRadians, 2 * pi);
	}

	myAngleInRadians = thetaInRadians;			
	myRadius = r;
}

void Position::IncrementPosition(float rChange, float angularDistChange) {
	const float pi = 3.14159265358979323846;

	// Note that angularDistChange is in unit distance
	// Thus it needs to be converted to angle
	// The convention is documented in positions.h
	float thetaChange = angularDistChange / myRadius;

	myAngleInRadians += thetaChange; 	

	if (myAngleInRadians < 0) {
		myAngleInRadians += 2 *pi;
	}

	if (myAngleInRadians > 2 * pi) {
		myAngleInRadians = fmod(myAngleInRadians, 2 * pi);
	}
	
	if (myRadius + rChange < 1) {
		myRadius = 1;
	} else {
		myRadius += rChange;
	}
}

void Position::Print() const {
	const float pi = 3.14159265358979323846;
	std::cout << "  The radius is: " << myRadius << " m\n";
	std::cout << "  The angle is: " << 180 / pi * myAngleInRadians << " deg\n";
}

bool Position::Sees(Position pos) const {
	if ((myRadius * cos(myAngleInRadians - pos.myAngleInRadians)) >= 1) 
		return true;
	else
		return false;
}

bool Position::IsAtStatue() const {
	if ((myRadius - 1) <= 1.E-12)
		return true;
	else 
		return false;	
}

bool Position::IsBetween(Position pos1, Position pos2) const {
	float angle1 = pos1.myAngleInRadians;
	float angle2 = pos2.myAngleInRadians;
	const float pi = 3.14159265358979323846;

	//! Make sure angle2 - angle1 < pi
	if ((angle2 - angle1) > pi) {
		float temp = angle1;
		angle1 = angle2;
		angle2 = temp;
	}

	//! Main loop to check whether angle B is between angle A and C
	//! Two conditions: cos (B - A) > cos (C - A), and cos (C - B) > cos (C - A)
	//! Note that C - A <= pi
	if (cos(myAngleInRadians - angle1) > cos(angle2 - angle1) && 
		cos(angle2 - myAngleInRadians) > cos(angle2 - angle1))
		return true;
	else
		return false;
}