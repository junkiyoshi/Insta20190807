#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetLineWidth(3);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateZ(ofGetFrameNum());

	auto deg_span = 15;
	auto theta_span = 5;
	for (int radius = 100; radius <= 300; radius += 75) {

		for (int deg = 0; deg < 360; deg += deg_span) {

			auto noise_source = glm::vec2(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));
			int theta = ofMap(ofNoise(noise_source.x * 0.005, noise_source.y * 0.005, ofGetFrameNum() * 0.008), 0, 1, 0, 180);

			if (theta > 90) {

				for (int tmp_theta = 90; tmp_theta < theta; tmp_theta += theta_span) {

					vector<glm::vec3> vertices_1, vertices_2;
					for (int tmp_deg = deg; tmp_deg <= deg + deg_span; tmp_deg++) {

						vertices_1.push_back(glm::vec3(radius * cos(tmp_deg * DEG_TO_RAD) * sin(tmp_theta * DEG_TO_RAD), radius * sin(tmp_deg * DEG_TO_RAD) * sin(tmp_theta * DEG_TO_RAD), radius * cos(tmp_theta * DEG_TO_RAD)));
						vertices_2.push_back(glm::vec3(radius * cos(tmp_deg * DEG_TO_RAD) * sin((tmp_theta + theta_span) * DEG_TO_RAD), radius * sin(tmp_deg * DEG_TO_RAD) * sin((tmp_theta + theta_span) * DEG_TO_RAD), radius * cos((tmp_theta + theta_span) * DEG_TO_RAD)));
					}

					reverse(vertices_2.begin(), vertices_2.end());

					ofFill();
					ofSetColor(239);

					ofBeginShape();
					ofVertices(vertices_1);
					ofVertices(vertices_2);
					ofEndShape(true);

					ofNoFill();
					ofSetColor(39);

					ofBeginShape();
					ofVertices(vertices_1);
					ofVertices(vertices_2);
					ofEndShape(true);
				}
			}
			else {

				for (int tmp_theta = 90; tmp_theta > theta; tmp_theta -= theta_span) {

					vector<glm::vec3> vertices_1, vertices_2;
					for (int tmp_deg = deg; tmp_deg <= deg + deg_span; tmp_deg++) {

						vertices_1.push_back(glm::vec3(radius * cos(tmp_deg * DEG_TO_RAD) * sin(tmp_theta * DEG_TO_RAD), radius * sin(tmp_deg * DEG_TO_RAD) * sin(tmp_theta * DEG_TO_RAD), radius * cos(tmp_theta * DEG_TO_RAD)));
						vertices_2.push_back(glm::vec3(radius * cos(tmp_deg * DEG_TO_RAD) * sin((tmp_theta + theta_span) * DEG_TO_RAD), radius * sin(tmp_deg * DEG_TO_RAD) * sin((tmp_theta + theta_span) * DEG_TO_RAD), radius * cos((tmp_theta + theta_span) * DEG_TO_RAD)));
					}

					reverse(vertices_2.begin(), vertices_2.end());

					ofFill();
					ofSetColor(239);

					ofBeginShape();
					ofVertices(vertices_1);
					ofVertices(vertices_2);
					ofEndShape(true);

					ofNoFill();
					ofSetColor(39);

					ofBeginShape();
					ofVertices(vertices_1);
					ofVertices(vertices_2);
					ofEndShape(true);
				}
			}
		}
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}