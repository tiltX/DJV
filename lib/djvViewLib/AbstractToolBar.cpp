//------------------------------------------------------------------------------
// Copyright (c) 2004-2015 Darby Johnston
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice,
//   this list of conditions, and the following disclaimer.
//
// * Redistributions in binary form must reproduce the above copyright notice,
//   this list of conditions, and the following disclaimer in the documentation
//   and/or other materials provided with the distribution.
//
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

#include <djvViewLib/AbstractToolBar.h>

#include <djvViewLib/AbstractActions.h>
#include <djvViewLib/Context.h>

#include <djvUI/IconLibrary.h>
#include <djvUI/Style.h>

namespace djv
{
    namespace ViewLib
    {
        struct AbstractToolBar::Private
        {
            Private(
                AbstractActions * actions,
                Context *         context) :
                actions(actions),
                context(context)
            {}

            Context *         context = nullptr;
            AbstractActions * actions = nullptr;
        };

        AbstractToolBar::AbstractToolBar(
            AbstractActions * actions,
            Context *         context,
            QWidget *         parent) :
            QToolBar(parent),
            _p(new Private(actions, context))
        {
            setAllowedAreas(Qt::TopToolBarArea | Qt::LeftToolBarArea | Qt::RightToolBarArea);
            setFloatable(false);
            //setMovable(false);
            const int iconSize = _p->context->style()->sizeMetric().iconSize;
            setIconSize(QSize(iconSize, iconSize));

            connect(
                context->style(),
                SIGNAL(sizeMetricsChanged()),
                SLOT(sizeMetricsCallback()));
        }

        AbstractToolBar::~AbstractToolBar()
        {}

        AbstractActions * AbstractToolBar::actions() const
        {
            return _p->actions;
        }

        Context * AbstractToolBar::context() const
        {
            return _p->context;
        }

        void AbstractToolBar::sizeMetricsCallback()
        {
            const int iconSize = _p->context->style()->sizeMetric().iconSize;
            setIconSize(QSize(iconSize, iconSize));
        }

    } // namespace ViewLib
} // namespace djv