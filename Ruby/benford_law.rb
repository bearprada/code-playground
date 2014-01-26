require 'net/http'
require 'json'
require 'rubygems'
require 'work_queue'

def request(wq, url)
    wq.enqueue_b {
        uri = URI(url)
        req = Net::HTTP::Get.new(uri.request_uri)
        req['User-agent'] = 'Mozilla 5.10'

        res = Net::HTTP.start(uri.hostname, uri.port) {|http|
          http.request(req)
        }

        open 'cached_response', 'w' do |io|
          io.write res.body
        end if res.is_a?(Net::HTTPSuccess)
        show(analysis(res.body))
    }
end

def terminal(wq)
    puts "------- terminal --------"
    wq.join
end

def analysis(html)
    result = {}
    (1..9).each { |i| result.store(i, 0) }
    html.scan(/[0-9]{1,}\.?[0-9]{1,}|[0-9]{1,}\,?[0-9]{1,}|[0-9]{1,}/).each do |i|
        k = i.strip().to_s()[0].to_i()
        if k > 0 and k <10
            result[k] += 1
        end
    end
    puts result
    return result
end

def show(result)
    total = result.inject(0) { |sum, a| sum + a[1] }
    puts "| p | times | our percentage | Benford's Low | "
    result.each do |k, v|
        puts "#{k}\t#{v}\t#{v*100.0/total}\t #{Math.log10(1.0+(1.0/k))*100}"
    end
    puts "-----------------------------------------------"
end

wq = WorkQueue.new 2, nil
url = "http://en.wikipedia.org/wiki/Benford%27s_law"
(0..10).each do |i|
    request(wq, url)
end
terminal(wq)
