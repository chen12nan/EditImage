import QtQuick 2.0

import org.nemomobile.contacts 1.0
import com.syberos.basewidgets 2.0
import com.syberos.multimedia.photos 2.0

MessageBrowseMain{
    id: mainView
    rightButtonText:"确定"

    Component.onDestruction:{
        gScreenInfo.setStatusBar(false)
    }
}
