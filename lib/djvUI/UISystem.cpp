// SPDX-License-Identifier: BSD-3-Clause
// Copyright (c) 2004-2020 Darby Johnston
// All rights reserved.

#include <djvUI/UISystem.h>

#include <djvUI/AVSettings.h>
#include <djvUI/ColorSpaceSettings.h>
#include <djvUI/DialogSystem.h>
#include <djvUI/GLFWSettings.h>
#include <djvUI/GeneralSettings.h>
#include <djvUI/FontSettings.h>
#include <djvUI/IconSystem.h>
#include <djvUI/MouseSettings.h>
#include <djvUI/Render2DSettings.h>
#include <djvUI/SettingsSystem.h>
#include <djvUI/Style.h>
#include <djvUI/StyleSettings.h>
#include <djvUI/UISettings.h>

#include <djvRender2D/RenderSystem.h>

#include <djvAV/AVSystem.h>

#include <djvSystem/Context.h>
#include <djvSystem/FileInfo.h>
#include <djvSystem/TextSystem.h>

using namespace djv::Core;

namespace djv
{
    namespace UI
    {
        struct UISystem::Private
        {
            std::shared_ptr<Style::Style> style;
        };

        void UISystem::_init(bool resetSettings, const std::shared_ptr<System::Context>& context)
        {
            ISystem::_init("djv::UI::UISystem", context);

            DJV_PRIVATE_PTR();

            addDependency(AV::AVSystem::create(context));
            addDependency(Render2D::RenderSystem::create(context));

            addDependency(Settings::SettingsSystem::create(resetSettings, context));
            Settings::AV::create(context);
            Settings::ColorSpace::create(context);
            Settings::GLFW::create(context);
            Settings::General::create(context);
            Settings::Font::create(context);
            Settings::Mouse::create(context);
            Settings::Render2D::create(context);
            Settings::UI::create(context);
            Settings::Style::create(context);
            addDependency(IconSystem::create(context));
            p.style = Style::Style::create(context);
            addDependency(DialogSystem::create(context));

            _logInitTime();
        }

        UISystem::UISystem() :
            _p(new Private)
        {}

        UISystem::~UISystem()
        {}

        std::shared_ptr<UISystem> UISystem::create(bool resetSettings, const std::shared_ptr<System::Context>& context)
        {
            auto out = context->getSystemT<UISystem>();
            if (!out)
            {
                out = std::shared_ptr<UISystem>(new UISystem);
                out->_init(resetSettings, context);
            }
            return out;
        }

        const std::shared_ptr<Style::Style>& UISystem::getStyle() const
        {
            return _p->style;
        }

    } // namespace UI
} // namespace djv

