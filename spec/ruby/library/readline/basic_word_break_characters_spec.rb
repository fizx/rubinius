require File.dirname(__FILE__) + '/../../spec_helper'

process_is_foreground do

  not_supported_on :ironruby do
    require 'readline'
    describe "Readline.basic_word_break_characters" do
      it "returns not nil" do
        Readline.basic_word_break_characters.should_not be_nil
      end
    end

    describe "Readline.basic_word_break_characters=" do
      it "returns the passed string" do
        Readline.basic_word_break_characters = "test"
        Readline.basic_word_break_characters.should == "test"
      end
    end
  end
end
