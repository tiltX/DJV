//------------------------------------------------------------------------------
// Copyright (c) 2018 Darby Johnston
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

#include <ViewLib/ImageView.h>

#include <ViewLib/Context.h>

#include <QVBoxLayout>

#include <condition_variable>

namespace djv
{
    namespace ViewLib
    {
        namespace
        {
            const size_t timeout = 10;

        } // namespace

        struct ImageView::Private
        {
            QPointer<Context> context;
            std::shared_ptr<AV::IO::Queue> queue;
            std::shared_ptr<AV::PixelData> pixelData;
            int timer = 0;
            std::condition_variable queueCV;
        };
        
        ImageView::ImageView(const std::shared_ptr<AV::IO::Queue> & queue, const QPointer<Context> & context, QWidget * parent) :
            QOpenGLWidget(parent),
            _p(new Private)
        {
            _p->context = context;
            _p->queue = queue;
            _p->timer = startTimer(timeout);
        }
        
        ImageView::~ImageView()
        {}

        void ImageView::timerEvent(QTimerEvent *)
        {
            std::unique_lock<std::mutex> lock(_p->queue->getMutex());
            if (_p->queueCV.wait_for(
                lock,
                std::chrono::milliseconds(timeout),
                [this]
            {
                return !_p->queue->isVideoEmpty();
            }))
            {
                _p->pixelData = _p->queue->getFront().second;
                update();
            }
        }
                
    } // namespace ViewLib
} // namespace djv
