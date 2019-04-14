//------------------------------------------------------------------------------
// Copyright (c) 2004-2019 Darby Johnston
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice,
//   this list of conditions, and the following disclaimer.
// * Redistributions in binary form must reproduce the above copyright notice,
//   this list of conditions, and the following disclaimer in the documentation
//   and/or other materials provided with the distribution.
// * Neither the names of the copyright holders nor the names of any
//   contributors may be used to endorse or promote products derived from this
//   software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//------------------------------------------------------------------------------

#include <djvDesktop/Application.h>

#include <djvUI/ButtonGroup.h>
#include <djvUI/GroupBox.h>
#include <djvUI/PushButton.h>
#include <djvUI/RowLayout.h>
#include <djvUI/Window.h>

#include <djvCore/Error.h>

using namespace djv;

int main(int argc, char ** argv)
{
    int r = 0;
    try
    {
        auto app = Desktop::Application::create(argc, argv);

        auto layout = UI::VerticalLayout::create(app.get());
        layout->setMargin(UI::MetricsRole::MarginLarge);
        layout->setSpacing(UI::MetricsRole::SpacingLarge);

        auto pushButtonGroup = UI::ButtonGroup::create(UI::ButtonType::Push);
        auto hLayout = UI::HorizontalLayout::create(app.get());
        hLayout->setMargin(UI::MetricsRole::Margin);
        for (size_t i = 0; i < 3; ++i)
        {
            std::stringstream ss;
            ss << "Push " << i;
            auto button = UI::PushButton::create(ss.str(), app.get());
            pushButtonGroup->addButton(button);
            hLayout->addChild(button);
        }
        pushButtonGroup->setPushCallback(
            [](int index)
        {
            std::cout << "Push = " << index << std::endl;
        });
        auto groupBox = UI::GroupBox::create("Push Buttons", app.get());
        groupBox->addChild(hLayout);
        layout->addChild(groupBox);

        auto toggleButtonGroup = UI::ButtonGroup::create(UI::ButtonType::Toggle);
        hLayout = UI::HorizontalLayout::create(app.get());
        hLayout->setMargin(UI::MetricsRole::Margin);
        for (size_t i = 0; i < 3; ++i)
        {
            std::stringstream ss;
            ss << "Toggle " << i;
            auto button = UI::PushButton::create(ss.str(), app.get());
            toggleButtonGroup->addButton(button);
            hLayout->addChild(button);
        }
        toggleButtonGroup->setToggleCallback(
            [](int index, bool value)
        {
            std::cout << "Toggle " << index << " = " << value << std::endl;
        });
        groupBox = UI::GroupBox::create("Toggle Buttons", app.get());
        groupBox->addChild(hLayout);
        layout->addChild(groupBox);

        auto radioButtonGroup = UI::ButtonGroup::create(UI::ButtonType::Radio);
        hLayout = UI::HorizontalLayout::create(app.get());
        hLayout->setMargin(UI::MetricsRole::Margin);
        for (size_t i = 0; i < 3; ++i)
        {
            std::stringstream ss;
            ss << "Radio " << i;
            auto button = UI::PushButton::create(ss.str(), app.get());
            radioButtonGroup->addButton(button);
            hLayout->addChild(button);
        }
        radioButtonGroup->setRadioCallback(
            [](int index)
        {
            std::cout << "Radio " << index << std::endl;
        });
        groupBox = UI::GroupBox::create("Radio Buttons", app.get());
        groupBox->addChild(hLayout);
        layout->addChild(groupBox);

        auto exclusiveButtonGroup = UI::ButtonGroup::create(UI::ButtonType::Exclusive);
        hLayout = UI::HorizontalLayout::create(app.get());
        hLayout->setMargin(UI::MetricsRole::Margin);
        for (size_t i = 0; i < 3; ++i)
        {
            std::stringstream ss;
            ss << "Exclusive " << i;
            auto button = UI::PushButton::create(ss.str(), app.get());
            exclusiveButtonGroup->addButton(button);
            hLayout->addChild(button);
        }
        exclusiveButtonGroup->setExclusiveCallback(
            [](int index)
        {
            std::cout << "Exclusive " << index << std::endl;
        });
        groupBox = UI::GroupBox::create("Exclusive Buttons", app.get());
        groupBox->addChild(hLayout);
        layout->addChild(groupBox);

        auto window = UI::Window::create(app.get());
        window->addChild(layout);
        window->show();

        return app->run();
    }
    catch (const std::exception & e)
    {
        std::cout << Core::Error::format(e) << std::endl;
    }
    return r;
}