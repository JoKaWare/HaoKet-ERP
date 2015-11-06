#include "editordelegate.h"

EditorDelegate::EditorDelegate(QObject *parent) : QItemDelegate(parent) {
    QObject::connect(this, SIGNAL(closeEditor(QWidget *, QAbstractItemDelegate::EndEditHint)),
                     this, SLOT(editorClose_(QWidget *, QAbstractItemDelegate::EndEditHint)));
}

void EditorDelegate::editorClose_(QWidget *editor, QAbstractItemDelegate::EndEditHint hint) {
    Q_UNUSED(editor);
    Q_UNUSED(hint);
    emit editorClose(this);
}

QWidget* EditorDelegate::createEditor(QWidget *parent,
                                      const QStyleOptionViewItem &option,
                                      const QModelIndex &index) const {
    if (index.column() == 1) {
        int command = index.model()->data(index, Qt::UserRole).toInt();
        if (command == FontSize) {
            return QItemDelegate::createEditor(parent, option, index);
        } else
        if (command == FontName) {
            QFontComboBox *editor = new QFontComboBox(parent);
            connect(editor, SIGNAL(activated(int)), this, SLOT(commitAndCloseEditor()));
            return editor;
        } else
        if (command == AligmentH) {
            QComboBox *editor = new QComboBox(parent);
            editor->addItem("Left",Qt::AlignLeft);
            editor->addItem("Center",Qt::AlignHCenter);
            editor->addItem("Right",Qt::AlignRight);
            editor->addItem("Justify",Qt::AlignJustify);
            connect(editor, SIGNAL(activated(int)), this, SLOT(commitAndCloseEditor()));
            return editor;
        } else
        if (command == AligmentV) {
            QComboBox *editor = new QComboBox(parent);
            editor->addItem("Top",Qt::AlignTop);
            editor->addItem("Center",Qt::AlignVCenter);
            editor->addItem("Bottom",Qt::AlignBottom);
            connect(editor, SIGNAL(activated(int)), this, SLOT(commitAndCloseEditor()));
            return editor;
        } else
        return QItemDelegate::createEditor(parent, option, index);
    }
    return 0;
}

void EditorDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const {
    if (index.column() == 1) {
        int command = index.model()->data(index, Qt::UserRole).toInt();
        if (command == AligmentH || command == AligmentV) {
            QString value = index.model()->data(index, Qt::EditRole).toString();
            QComboBox *ed = qobject_cast<QComboBox*>(editor);
            ed->setCurrentIndex(ed->findText(value));
        } else
        if (command == FontName) {
            QString value = index.model()->data(index, Qt::EditRole).toString();
            QFontComboBox *ed = qobject_cast<QFontComboBox*>(editor);
            ed->setCurrentFont(QFont(value));
        } else
        if (command == FontSize) {
            QItemDelegate::setEditorData(editor,index);
        } else
        QItemDelegate::setEditorData(editor,index);
    } else return;
}

void EditorDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex& index) const {
    if (index.column() == 1) {
        int command = index.model()->data(index, Qt::UserRole).toInt();
        if (command == AligmentH || command == AligmentV) {
            QComboBox *ed = static_cast<QComboBox*>(editor);
            model->setData(index, ed->currentIndex());
        } else
        if (command == FontName) {
            QFontComboBox *ed = static_cast<QFontComboBox*>(editor);
            model->setData(index, ed->currentFont().family());
        } else
        if (command == FontSize) {
            QItemDelegate::setModelData(editor,model,index);
        } else
        QItemDelegate::setModelData(editor,model,index);
    } return;
}

void EditorDelegate::commitAndCloseEditor() {
    QWidget *editor;
    editor = qobject_cast<QWidget*>(sender());
    emit commitData(editor);
    emit closeEditor(editor);
}
