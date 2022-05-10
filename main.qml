import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Controls.Basic
Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    GridLayout{
        anchors.fill: parent;
        columns: 3
        TextField{
            id: newTestTF
            text: Controller.newTestObject.test;
        }
        TextField{
            text: Controller.newTestObject.test;
            readOnly: true
        }

        Binding{
            target: Controller.newTestObject
            property: "test"
            value: newTestTF.text
        }

        Button{
            text: "new"
            onClicked: Controller.createNewObject();
        }

        TextField{
            id: oldTestTF
            text: Controller.oldTestObject.test;

        }

        TextField{
            text: Controller.oldTestObject.test;
            readOnly: true
        }
        Binding{
            target: Controller.oldTestObject
            property: "test"
            value: oldTestTF.text
        }
        Button{
            text: "old"
            onClicked: Controller.createOldObject();
        }

        Rectangle{
            Layout.fillWidth: true
            color: "black"
            implicitHeight: 1
            Layout.columnSpan: 3
        }

        TextField{
            id: bindableNewTestTF
            text: Controller.bindableNewTestObject.test;
        }
        TextField{
            text: Controller.bindableNewTestObject.test;
            readOnly: true
        }

        Binding{
            target: Controller.bindableNewTestObject
            property: "test"
            value: bindableNewTestTF.text
        }

        Button{
            text: "new"
            onClicked: Controller.createbindableNewObject();
        }

        TextField{
            id: bindableOldTestTF
            text: Controller.bindableOldTestObject.test;

        }

        TextField{
            text: Controller.bindableOldTestObject.test;
            readOnly: true
        }
        Binding{
            target: Controller.bindableOldTestObject
            property: "test"
            value: bindableOldTestTF.text
        }
        Button{
            text: "old"
            onClicked: Controller.createbindableOldObject();
        }
    }

}
