#include <opencv2/opencv.hpp>
#include <mediapipe/framework/port/opencv_imgproc_inc.h>
#include <mediapipe/framework/port/opencv_imgcodecs_inc.h>
#include <mediapipe/framework/formats/image_frame.h>
#include <mediapipe/framework/formats/landmark.pb.h>
#include <mediapipe/framework/formats/rect.pb.h>
#include <mediapipe/framework/formats/classification.pb.h>
#include <mediapipe/framework/formats/point.pb.h>
#include <mediapipe/framework/formats/rect.pb.h>
#include <mediapipe/framework/calculator_framework.h>
#include <mediapipe/framework/formats/image_frame_opencv.h>
#include <mediapipe/framework/formats/landmark_list.h>
#include <mediapipe/framework/formats/rect.h>

int main() {
    cv::VideoCapture cam(0);
    mp::FaceMesh face_mesh(true);
    cv::Size screen_size = cv::Size(pyautogui::size().width(), pyautogui::size().height());
    
    while (true) {
        cv::Mat frame;
        cam.read(frame);
        cv::flip(frame, frame, 1);

        cv::Mat rgb_frame;
        cv::cvtColor(frame, rgb_frame, cv::COLOR_BGR2RGB);

        auto output = face_mesh.Process(mp::InputFrame::FromExternalRgb(rgb_frame));
        auto landmark_points = output.multi_face_landmarks();

        int frame_h = frame.rows;
        int frame_w = frame.cols;

        if (!landmark_points.empty()) {
            auto landmarks = landmark_points[0].landmark();
            for (int id = 474; id < 478; ++id) {
                int x = static_cast<int>(landmarks[id].x() * frame_w);
                int y = static_cast<int>(landmarks[id].y() * frame_h);
                cv::circle(frame, cv::Point(x, y), 3, cv::Scalar(0, 255, 0));
                if (id == 475) {
                    double screen_x = screen_size.width * landmarks[id].x();
                    double screen_y = screen_size.height * landmarks[id].y();
                    pyautogui::moveTo(screen_x, screen_y);
                }
            }

            std::vector<mp::NormalizedLandmark> left = {landmarks[145], landmarks[159]};
            for (const auto& landmark : left) {
                int x = static_cast<int>(landmark.x() * frame_w);
                int y = static_cast<int>(landmark.y() * frame_h);
                cv::circle(frame, cv::Point(x, y), 3, cv::Scalar(0, 255, 255));
            }

            if ((left[0].y() - left[1].y()) < 0.004) {
                pyautogui::click();
                pyautogui::sleep(1);
            }
        }

        cv::imshow("Eye Controlled Mouse", frame);
        cv::waitKey(1);
    }

    return 0;
}
