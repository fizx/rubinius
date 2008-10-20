def test_case
{"RawParseTree"=>
  [:dstr,
   "s1 '",
   [:evstr, [:const, :RUBY_PLATFORM]],
   [:str, "' s2\n"],
   [:str, "(string)"],
   [:str, "\n"]],
 "Ruby"=>"<<-EOF\ns1 '\#{RUBY_PLATFORM}' s2\n\#{__FILE__}\n        EOF\n",
 "ParseTree"=>
  s(:dstr,
   "s1 '",
   s(:evstr, s(:const, :RUBY_PLATFORM)),
   s(:str, "' s2\n"),
   s(:str, "(string)"),
   s(:str, "\n")),
 "Ruby2Ruby"=>"\"s1 '\#{RUBY_PLATFORM}' s2\\n(string)\\n\""}
end