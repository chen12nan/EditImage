import QtQuick 2.0
import com.syberos.basewidgets 2.0
import base 1.0

CPageStackWindow {
    initialPage:CPage{
        width:parent.width
        height:parent.height

        SyberImage{
            id: contentImage
            anchors.fill: parent

            MouseArea{
                anchors.fill: parent

                onPressed: {
                    contentImage.mousePress(Qt.point(mouse.x, mouse.y));
                }
                onPositionChanged: {
                    contentImage.mouseMouse(Qt.point(mouse.x, mouse.y));
                }
            }
        }
    }
}
